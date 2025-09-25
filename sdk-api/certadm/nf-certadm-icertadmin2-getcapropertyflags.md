# ICertAdmin2::GetCAPropertyFlags

## Description

The **GetCAPropertyFlags** method retrieves the property flags for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) property. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

The property flags can be examined to determine the data type and to determine whether the property is indexed.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see **ICertConfig**.

**Important** **GetCAPropertyFlags** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `PropId` [in]

Specifies the property identifier. For information about this parameter, see the table in
[ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty).

### `pPropFlags` [out]

A pointer to a value that represents the property flags.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates the method was successful.

### VB

A **Long** representing the property flags.

## Remarks

The **LONG** value retrieved by calling this method can be examined to determine the data type and the indexed status. To determine the data type and indexed status, use the PROPTYPE_MASK and PROPFLAGS_INDEXED values, respectively.

#### Examples

The following example assumes the [ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) interface pointer is valid.

```cpp
BSTR bstrCA = NULL;
LONG nFlags;  // Variable to contain the property flags.

bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
if (NULL == bstrCA)
{
    printf("Failed to allocate memory for bstrCA\n");
    exit(1);
}

// Retrieve a property's flags.
hr = pCertAdmin2->GetCAPropertyFlags(bstrCA,
                                     CR_PROP_EXITCOUNT,
                                     &nFlags);
if (FAILED(hr))
{
    printf("Failed GetCAPropertyFlags\n");
    SysFreeString(bstrCA);
    exit(1);  // Or other error action.
}
// Display the property data type.
switch (nFlags & PROPTYPE_MASK)
{
    case PROPTYPE_BINARY:
        printf("Type is BINARY\n");
        break;
    case PROPTYPE_DATE:
        printf("Type is DATE\n");
        break;
    case PROPTYPE_LONG:
        printf("Type is LONG\n");
        break;
    case PROPTYPE_STRING:
        printf("Type is STRING\n");
        break;
    default:
        printf("Unexpected data type.\n");
        break;
}
// Display the property's indexed status.
printf("Property %s indexed\n",
       nFlags & PROPFLAGS_INDEXED ? "is" : "is not");

SysFreeString(bstrCA);
```