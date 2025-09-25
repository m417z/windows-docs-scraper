# IShellImageData::GetEncoderParams

## Description

Gets the current set of encoder parameters.

## Parameters

### `pguidFmt` [in]

Type: **GUID***

A pointer to a GUID that specifies the encoder. This must be an encoder supported by GDI+. If this parameter is **NULL**, an unhandled exception results.

### `ppEncParams` [out]

Type: **EncoderParameters****

The address of a pointer to an array of [EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85)) objects.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Several circumstances can generate this return value.<br><br>* The image was not decoded or the decoding process failed.<br>* *pguidFmt* refers to a format not supported by GDI+.<br>* An internal call failed. |