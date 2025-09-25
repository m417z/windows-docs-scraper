# RoIsApiContractPresent function

## Description

Returns true or false to indicate whether the API contract with the specified name and major and minor version number is present.

## Parameters

### `name`

Type: **PCWSTR**

The name of the API contract.

### `majorVersion`

Type: **UINT16**

The major version number of the API contract.

### `minorVersion`

Type: **UINT16**

The minor version number of the API contract.

### `present`

Type: **BOOL***

True if the specified API contract is present; otherwise, false.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified API contract is valid and is present. |
| **RO_E_METADATA_NAME_NOT_FOUND** | The input string is not an API contract defined in any examined .winmd file. |
| **RO_E_METADATA_NAME_IS_NAMESPACE** | The input string is an existing namespace rather than an API contract name. |

## Remarks

This function was introduced in Windows 10, version 1809 (build 17763).

## See also