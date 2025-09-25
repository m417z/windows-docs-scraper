# IMAGE_DATA_DIRECTORY structure

## Description

Represents the data directory.

## Members

### `VirtualAddress`

The relative virtual address of the table.

### `Size`

The size of the table, in bytes.

## Remarks

The following is a list of the data directories. Offsets are relative to the beginning of the optional header.

| Offset (PE/PE32+) | Description |
| --- | --- |
| 96/112 | Export table address and size |
| 104/120 | Import table address and size |
| 112/128 | Resource table address and size |
| 120/136 | Exception table address and size |
| 128/144 | Certificate table address and size |
| 136/152 | Base relocation table address and size |
| 144/160 | Debugging information starting address and size |
| 152/168 | Architecture-specific data address and size |
| 160/176 | Global pointer register relative virtual address |
| 168/184 | Thread local storage (TLS) table address and size |
| 176/192 | Load configuration table address and size |
| 184/200 | Bound import table address and size |
| 192/208 | Import address table address and size |
| 200/216 | Delay import descriptor address and size |
| 208/224 | The CLR header address and size |
| 216/232 | Reserved |

## See also

[IMAGE_OPTIONAL_HEADER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)