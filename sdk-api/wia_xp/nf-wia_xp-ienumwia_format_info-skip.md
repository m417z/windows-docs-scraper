# IEnumWIA_FORMAT_INFO::Skip

## Description

The **IEnumWIA_FORMAT_INFO::Skip** method skips the specified number of structures in the enumeration.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of structures to skip.

## Return value

Type: **HRESULT**

This method returns S_OK if it is able to skip the specified number of elements. It returns S_FALSE if it is unable to skip the specified number of elements. If the method fails, it returns a standard COM error.