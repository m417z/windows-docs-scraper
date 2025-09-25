# LICINFO structure

## Description

Contains parameters that describe the licensing behavior of a class factory that supports licensing. The structure is filled by calling the [IClassFactory2::GetLicInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-getlicinfo) method.

## Members

### `cbLicInfo`

The size of the structure, in bytes.

### `fRuntimeKeyAvail`

Indicates whether this class factory allows the creation of its objects on an unlicensed machine through the use of a license key. If **TRUE**, [IClassFactory2::RequestLicKey](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-requestlickey) can be called to obtain the key. If **FALSE**, objects can be created only on a fully licensed machine.

### `fLicVerified`

Indicates whether a full machine license exists such that calls to [IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance) and [IClassFactory2::RequestLicKey](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-requestlickey) will succeed. If **TRUE**, the full machine license exists. Thus, objects can be created freely. and a license key is available if **fRuntimeKeyAvail** is also **TRUE**. If **FALSE**, this class factory cannot create any instances of objects on this machine unless the proper license key is passed to [IClassFactory2::CreateInstanceLic](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-createinstancelic).

## See also

[IClassFactory2::GetLicInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-getlicinfo)