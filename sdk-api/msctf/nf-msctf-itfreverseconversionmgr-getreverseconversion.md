# ITfReverseConversionMgr::GetReverseConversion

## Description

[**GetReverseConversion** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For internal use only.]

Retrieves an [ITfReverseConversion](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreverseconversion) object that can perform reverse conversions.

## Parameters

### `langid` [in]

 The language ID of the profile to which the target strings belong.

### `guidProfile` [in]

 The GUID of the profile to which the target strings belong.

### `dwflag` [in]

| Value | Meaning |
| --- | --- |
| **TF_RCM_COMLESS**<br><br>0x00000001 | Activate the reverse conversion interface without COM. |
| **TF_RCM_VKEY**<br><br>0x00000002 | The output should be an array of virtual key codes (instead of character key codes). |
| **TF_RCM_HINT_READING_LENGTH**<br><br>0x00000004 | The reverse conversion should prioritize the order of entries in the output list based on the length of input sequence, with the shortest sequences first. It is possible that an input sequence with a low collision count might be much higher than an input sequence with a similar (but slightly higher) collision count. The interpretation of this flag varies depending on the IME. |
| **TF_RCM_HINT_COLLISION**<br><br>0x00000008 | The reverse conversion should prioritize the order of entries in the output list based on the collision count, with the entries containing the lowest number of collisions first. If an input sequence corresponds to many more characters than a slightly longer input sequence, it might be preferable to use the longer input sequence instead. The IME determines whether this flag will affect the reverse conversion output. |

### `ppReverseConversion` [out]

 A pointer to the address of the ITfReverseConversion object that can perform the specified reverse conversion.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | An [ITfReverseConversion](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreverseconversion) for the specified *langid* and *guidProfile* combination is available. |
| E_NOTIMPL | The specified *langid* and *guidProfile* combination does not support reverse conversion. |
| E_FAIL | An unspecified error occurred. |

## Remarks

A reverse conversion provides the keystroke sequences required to create the specified string.

When neither the **TF_RCM_HINT_COLLISION** or **TF_RCM_HINT_READING_LENGTH** flag is specified for *dwflag*, the IME might not arrange the output in any sort of order.

## See also

[ITfReverseConversionMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreverseconversionmgr)