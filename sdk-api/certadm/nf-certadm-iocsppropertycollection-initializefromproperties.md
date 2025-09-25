# IOCSPPropertyCollection::InitializeFromProperties

## Description

The **InitializeFromProperties** method creates a property set from the properties contained in an existing server configuration.

## Parameters

### `pVarProperties` [in]

|  |  |
| --- | --- |
| **C++** | A pointer to an array that contains the property values. Each array element is a **VARIANT** array that contains the property name **BSTR** and a value **VARIANT**. |
| **VB** | An array that contains the property values. Each array element is a **Variant** array that contains the property name **String** and a value **Variant**. |

## Return value

### VB

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

If the method returns **E_UNEXPECTED**, the array pointed to by the *pVarProperties* parameter contained duplicate properties.

If the method returns **DISP_E_ARRAYISLOCKED**, the array pointed to by the *pVarProperties* parameter is locked.

## See also

[IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection)