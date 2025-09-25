# IProvideMultipleClassInfo::GetInfoOfIndex

## Description

Retrieves the type information from the specified index.

## Parameters

### `iti` [in]

The index of the type information for which you want to obtain information. Index 0 is the default interface of the extender object; index *pcti-1 is the index of the base object.

### `dwFlags` [in]

A bitfield indicating which out parameters are being requested. Indicating a particular flag results in the appropriate information being assigned to the associated out parameter. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MULTICLASSINFO_GETTYPEINFO**<br><br>0x00000001 | Indicates a request for *pptiCoClass* information. |
| **MULTICLASSINFO_GETNUMRESERVEDDISPIDS**<br><br>0x00000002 | Indicates a request for *pcdispidReserved* and *pdwTIFlags* information. |
| **MULTICLASSINFO_GETIIDPRIMARY**<br><br>0x00000004 | Indicates a request for *piidPrimary* information. |
| **MULTICLASSINFO_GETIIDSOURCE**<br><br>0x00000008 | Indicates a request for *piidSource* information. |

### `pptiCoClass` [out]

The [coclass](https://msdn.microsoft.com/) type information for the requested contributor. See [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo).

### `pdwTIFlags` [out]

The bitfield flag.

### `pcdispidReserved` [out]

The number of DISPIDs the default interface of *pptiCoClass* reserves for its own use. This number can be used to calculate the amount to offset DISPIDs in the reserved range implemented by the object this class is extending.

### `piidPrimary` [out]

The IID of the primary interface for the requested contributor.

### `piidSource` [out]

The IID of the default source interface for the requested contributor.

## Return value

This method can return the standard return values E_INVALIDARG, E_POINTER, E_FAIL, and S_OK.

## See also

[IProvideMultipleClassInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iprovidemultipleclassinfo)