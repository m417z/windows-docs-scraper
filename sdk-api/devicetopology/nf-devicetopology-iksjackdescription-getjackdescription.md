# IKsJackDescription::GetJackDescription

## Description

The **GetJackDescription** method gets a description of an audio jack.

## Parameters

### `nJack` [in]

The jack index. If the connection consists of *n* jacks, the jacks are numbered from 0 to *n*– 1. To get the number of jacks, call the [IKsJackDescription::GetJackCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackcount) method.

### `pDescription` [out]

Pointer to a caller-allocated buffer into which the method writes a structure of type [KSJACK_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_description) that contains information about the jack. The buffer size must be at least sizeof(KSJACK_DESCRIPTION).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nJack* is not a valid jack index. |
| **E_POINTER** | Pointer *pDescription* is **NULL**. |

## Remarks

When a user needs to plug an audio endpoint device into a jack or unplug it from a jack, an audio application can use the descriptive information that it retrieves from this method to help the user to find the jack. This information includes:

* The physical location of the jack on the computer chassis or external box.
* The color of the jack.
* The type of physical connector used for the jack.
* The mapping of channels to the jack.

For more information, see [KSJACK_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_description).

## See also

[IKsJackDescription Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription)

[IKsJackDescription::GetJackCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackcount)

[KSJACK_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/devicetopology/ns-devicetopology-ksjack_description)