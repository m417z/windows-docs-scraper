# ITfFnGetPreferredTouchKeyboardLayout::GetLayout

## Description

Obtains the touch keyboard layout identifier of the layout that the IME directs the touch keyboard to show while the IME is active.

## Parameters

### `pTKBLayoutType` [out]

Pointer to a [TKBLayoutType](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tkblayouttype) enumeration that receives the layout type.

### `pwPreferredLayoutId` [out]

Pointer to a **WORD** value that receives the layout identifier.

## Return value

The touch keyboard always expects S_OK.

## Remarks

[TKBLayoutType](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tkblayouttype) is an enumeration with the following values.

|  |  |
| --- | --- |
| TKBLT_UNDEFINED | Undefined. |
| TKBLT_CLASSIC | The touch keyboard is to use a classic layout.<br><br>Classic layouts represent the legacy layouts of physical keyboards. |
| TKBLT_OPTIMIZED | The touch keyboard is to use a touch-optimized layout.<br><br>Touch-optimized layouts have been specifically designed with touch in mind. |

The layout identifiers returned by this API must be one from the following list.
Each identifier is specific to a certain language, and these are all specific to the touch keyboard.
There is no way to request support for other layouts, or to add new touch optimized layouts dynamically.

| Layout Definition | Value | Supported Input Language |
| --- | --- | --- |
| TKBL_UNDEFINED | 0 | n/a |
| TKBL_CLASSIC_TRADITIONAL_CHINESE_PHONETIC | 0x0404 | CHT |
| TKBL_CLASSIC_TRADITIONAL_CHINESE_CHANGJIE | 0xF042 | CHT |
| TKBL_CLASSIC_TRADITIONAL_CHINESE_DAYI | 0xF043 | CHT |
| TKBL_OPT_JAPANESE_ABC | 0x0411 | JPN |
| TKBL_OPT_KOREAN_HANGUL_2_BULSIK | 0x0412 | KOR |
| TKBL_OPT_SIMPLIFIED_CHINESE_PINYIN | 0x0804 | CHS |
| TKBL_OPT_TRADITIONAL_CHINESE_PHONETIC | 0x0404 | CHT |

## See also

[ITfFnGetPreferredTouchKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffngetpreferredtouchkeyboardlayout)