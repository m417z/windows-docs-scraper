# IDebugDataSpaces4::ReadImageNtHeaders

## Description

The **ReadImageNtHeaders** method returns the NT headers for the specified image loaded in the target.

## Parameters

### `ImageBase` [in]

Specifies the location in the target's virtual address space of the image whose NT headers are being requested.

### `Headers` [out]

Receives the NT headers for the specified image.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | No NT headers were found for the specified image. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If the image's NT headers are 32-bit, they are automatically converted to 64-bit for consistency. To determine if the headers were originally 32-bit, look at the value of **Headers.OptionalHeader.Magic**. If the value is IMAGE_NT_OPTIONAL_HDR32_MAGIC, the NT headers were originally 32-bit; otherwise the value is IMAGE_NT_OPTIONAL_HDR64_MAGIC, indicating the NT headers were originally 64-bit.

This method will not read ROM headers.

IMAGE_NT_HEADERS64, IMAGE_NT_OPTIONAL_HDR32_MAGIC, and IMAGE_NT_OPTIONAL_HDR64_MAGIC appear in the Microsoft Windows SDK header file winnt.h. IMAGE_NT_HEADERS64 is the 64-bit equivalent of IMAGE_NT_HEADERS, which is described in the Windows SDK documentation.