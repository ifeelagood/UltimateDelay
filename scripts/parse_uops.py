import os,sys
import pathlib

import requests
import tqdm
import lxml.etree

root = pathlib.Path(__file__).parent.parent
assert (root / "src").is_dir() and (root / "src/main.cpp").is_file(), "not in correct location"

def download_instructions(xml_path, bs=2**16):
    if not (xml_path.exists() and xml_path.is_file()):
        try:
            r = requests.get("https://uops.info/instructions.xml", stream=True)

            total_size = int(r.headers.get("content-length", 0))
            with tqdm.tqdm(total=total_size, unit="B", unit_scale=True, desc="downloading instructions.xml") as pbar:
                with open(xml_path, "wb") as f:
                    for chunk in r.iter_content(bs):
                        pbar.update(len(chunk))
                        f.write(chunk)

            print("successfully downloaded instructions.xml")
        except Exception as e:
            print(f"failed to download instructions.xml: {e}")

    else:
        print("instructions.xml already exists")

def parse_instructions(xml_path):
    tree = lxml.etree.parse(xml_path)

    head = tree.getroot()

    print(head)

if __name__ == "__main__":
    xml_path = root / "res" / "instructions.xml"
    xml_path.parent.mkdir(parents=True, exist_ok=True)

    download_instructions(xml_path)
    parse_instructions(xml_path)

