# IMFOutputSchema::GetSchemaType

## Description

Retrieves the output protection system that is represented by this object. Output protection systems are identified by GUID value.

## Parameters

### `pguidSchemaType` [out]

Receives the GUID that identifies the output protection system.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFOutputSchema](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputschema)