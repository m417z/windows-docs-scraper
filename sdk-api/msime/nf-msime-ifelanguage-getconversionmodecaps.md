# IFELanguage::GetConversionModeCaps

## Description

Gets the conversion mode capability of the [IFELanguage](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifelanguage) object.

## Parameters

### `pdwCaps` [out]

The capabilities, represented as a combination of one or more of the following flags:

| Value | Meaning |
| --- | --- |
| **FELANG_CMODE_MONORUBY** | Mono-ruby. |
| **FELANG_CMODE_NOPRUNING** | No pruning. |
| **FELANG_CMODE_KATAKANAOUT** | Katakana output. |
| **FELANG_CMODE_HIRAGANAOUT** | Default output. |
| **FELANG_CMODE_HALFWIDTHOUT** | Half-width output. |
| **FELANG_CMODE_FULLWIDTHOUT** | Full-width output. |
| **FELANG_CMODE_BOPOMOFO** |  |
| **FELANG_CMODE_HANGUL** |  |
| **FELANG_CMODE_PINYIN** |  |
| **FELANG_CMODE_PRECONV** | Do conversion as follows:<br><br>* Roma-ji to kana.<br>* Autocorrect before conversion.<br>* Periods, comma, and brackets. |
| **FELANG_CMODE_RADICAL** |  |
| **FELANG_CMODE_UNKNOWNREADING** |  |
| **FELANG_CMODE_MERGECAND** | Merge display with the same candidate. |
| **FELANG_CMODE_ROMAN** |  |
| **FELANG_CMODE_BESTFIRST** | Make only the first best. |
| **FELANG_CMODE_USENOREVWORDS** | Use invalid revword on REV/RECONV. |
| **FELANG_CMODE_NONE** | [IME_SMODE_NONE](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_PLAURALCLAUSE** | [IME_SMODE_PLAURALCLAUSE](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_SINGLECONVERT** | [IME_SMODE_SINGLECONVERT](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_AUTOMATIC** | [IME_SMODE_AUTOMATIC](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_PHRASEPREDICT** | [IME_SMODE_PHRASEPREDICT](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_CONVERSATION** | [IME_SMODE_CONVERSATION](https://learn.microsoft.com/windows/desktop/Intl/ime-sentence-mode-values) |
| **FELANG_CMODE_NAME** | Name mode (MSKKIME). |
| **FELANG_CMODE_NOINVISIBLECHAR** | Remove invisible chars (for example, the tone mark). |

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## See also

[IFELanguage](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifelanguage)