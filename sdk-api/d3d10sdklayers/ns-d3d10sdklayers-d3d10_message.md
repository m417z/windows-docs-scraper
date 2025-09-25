# D3D10_MESSAGE structure

## Description

A debug message in the Information Queue.

## Members

### `Category`

Type: **[D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category)**

The category of the message. See [D3D10_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_category).

### `Severity`

Type: **[D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity)**

The severity of the message. See [D3D10_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_severity).

### `ID`

Type: **[D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id)**

The ID of the message. See [D3D10_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ne-d3d10sdklayers-d3d10_message_id).

### `pDescription`

Type: **const char***

The message string.

### `DescriptionByteLength`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of pDescription in bytes.

## Remarks

This structure is returned from [ID3D10InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-getmessage) as part of the Information Queue feature (see [ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)