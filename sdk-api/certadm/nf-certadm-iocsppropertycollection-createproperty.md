# IOCSPPropertyCollection::CreateProperty

## Description

The **CreateProperty** method creates a new property and adds it to a property set.

## Parameters

### `bstrPropName` [in]

A string that contains the name of the new property object.

### `pVarPropValue` [in]

|  |  |
| --- | --- |
| **C++** | A pointer to the new property object. |
| **VB** | The new property object. |

### `ppVal` [out]

A pointer to an [IOCSPProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspproperty) interface for the newly created object.

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

An
[IOCSPProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspproperty)
interface for the newly created object.

## See also

[IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection)