# IKsJackDescription2::GetJackDescription2

## Description

The **GetJackDescription2** method gets the description of a specified audio jack.

## Parameters

### `nJack` [in]

The index of the jack to get a description for. If the connection consists of *n* jacks, the jacks are numbered from 0 to *n*– 1. To get the number of jacks, call the [IKsJackDescription::GetJackCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackcount) method.

### `pDescription2` [out]

Pointer to a caller-allocated buffer into which the method writes a structure of type [KSJACK_DESCRIPTION2](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_description2) that contains information about the jack. The buffer size must be at least `sizeof(KSJACK_DESCRIPTION2)`.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nJack* is not a valid jack index. |
| **E_POINTER** | Pointer *pDescription* is **NULL**. |

## See also

[IKsJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription2)