# InkRecognitionStatus enumeration

## Description

Specifies whether an error occurred during recognition and, if so, which error occurred.

## Constants

### `IRS_NoError:0`

Specifies no error.

### `IRS_Interrupted:0x1`

The recognition was interrupted by a call to [StopBackgroundRecognition](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-stopbackgroundrecognition).

### `IRS_ProcessFailed:0x2`

The ink recognition process failed.

### `IRS_InkAddedFailed:0x4`

The ink could not be added.

### `IRS_SetAutoCompletionModeFailed:0x8`

The *character Autocomplete* mode could not be set.

### `IRS_SetStrokesFailed:0x10`

The strokes could not be set.

### `IRS_SetGuideFailed:0x20`

The recognition guide could not be set.

### `IRS_SetFlagsFailed:0x40`

The flags could not be set.

### `IRS_SetFactoidFailed:0x80`

The factoid could not be set.

### `IRS_SetPrefixSuffixFailed:0x100`

The suffix or the prefix could not be set.

### `IRS_SetWordListFailed:0x200`

The word list could not be set.

## Remarks

The SetGuideFailed, SetFlagsFailed, SetFactoidFailed, and SetPrefixSuffixFailed members are redundant because an error is also raised when the corresponding properties are set.

## See also

[CharacterAutoCompletion Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_characterautocompletionmode)

[Factoid Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_factoid)

[Guide Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_guide)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[PrefixText Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_prefixtext)

[Recognition Event [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognition)

[RecognitionFlags Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags)

[SuffixText Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_suffixtext)

[WordList Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_wordlist)