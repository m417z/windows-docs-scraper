# IWDFNamedPropertyStore::SetNamedValue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetNamedValue** method sets the value of a property.

## Parameters

### `pszName` [in]

A pointer to a null-terminated string that contains the name of the property.

### `pv` [in]

A pointer to the value that the property is set to.

## Return value

**SetNamedValue** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The following variant types are supported for property values. The following table shows the types of values that the framework writes for particular variant types.

| Variant type | Write |
| --- | --- |
| VT_BSTR | Writes a string value. |
| VT_LPWSTR |
| VT_LPSTR |
| VT_I1 | Writes an integer value. |
| VT_UI1 |
| VT_I2 |
| VT_UI2 |
| VT_I4 |
| VT_UI4 |
| VT_UINT |
| VT_BLOB | Writes a binary value. |
| VT_VECTOR | VT_LPWSTR | Writes a string array. |

For more information, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

## See also

[IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore)