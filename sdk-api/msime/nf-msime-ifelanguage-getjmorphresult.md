# IFELanguage::GetJMorphResult

## Description

Gets morphological analysis results.

## Parameters

### `dwRequest` [in]

The conversion request. It can be one of the following values:

#### FELANG_REQ_CONV

#### FELANG_REQ_RECONV

#### FELANG_REQ_REV

### `dwCMode` [in]

Specifies the conversion output characters and conversion options. This value is a combination of one or more of the following flags:

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

### `cwchInput` [in]

The number of characters in *pwchInput*.

### `pwchInput` [in]

Input characters to be converted by the morphology engine. This must be a UNICODE string.

Set this parameter to **NULL** to get the next entry for the previously input string, with the next rank. The order in which next entries are returned is defined by the implementation.

### `pfCInfo` [in]

The information for each column, where each *pfCInfo[x]* corresponds to *pwchInput[x]*. Each **DWORD** can be a combination of the flags below:

#### FELANG_CLMN_WBREAK

#### FELANG_CLMN_NOWBREAK

#### FELANG_CLMN_PBREAK

#### FELANG_CLMN_NOPBREAK

#### FELANG_CLMN_FIXR

#### FELANG_CLMN_FIXD

### `ppResult` [out]

The address of a MORRSLT structure that receives the morphology result data.

**GetJMorphResult** allocates memory using the OLE task allocator for the returned data, and sets the *pResult* to point to the memory.
The application must free the memory pointed to by *pResult*, by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | More candidates exist. If you call this function again with *pwchInput* equal to **NULL**, it will get the next best candidate for the previous *pwchInput*. |
| **S_FALSE** | No result. |
| **E_NOCAND** | No more candidates. |
| **E_LARGEINPUT** | input too large. |
| **ERROR_SEM_TIMEOUT** | Mutex timeout is occurred. |

## See also

[IFELanguage](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifelanguage)