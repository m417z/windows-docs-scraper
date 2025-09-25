# IMFOutputSchema::GetOriginatorID

## Description

Retrieves a GUID identifying the input trust authority (ITA) that generated this output schema object.

## Parameters

### `pguidOriginatorID` [out]

Receives a GUID that identifies the originating ITA.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

All of the policy objects and output schemas from the same ITA should return the same originator identifier (including dynamic policy changes). This value enables the OTA to distinguish policies that originate from different ITAs, so that the OTA can update dynamic policies correctly.

## See also

[IMFOutputSchema](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputschema)