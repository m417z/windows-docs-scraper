# D3D11_MESSAGE structure

## Description

A debug message in the Information Queue.

## Members

### `Category`

Type: **[D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category)**

The category of the message. See [D3D11_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_category).

### `Severity`

Type: **[D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity)**

The severity of the message. See [D3D11_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_severity).

### `ID`

Type: **[D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id)**

The ID of the message. See [D3D11_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_message_id).

### `pDescription`

Type: **const char***

The message string.

### `DescriptionByteLength`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of pDescription in bytes.

## Remarks

This structure is returned from [ID3D11InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-getmessage) as part of the Information Queue feature (see [ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue)).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-structures)