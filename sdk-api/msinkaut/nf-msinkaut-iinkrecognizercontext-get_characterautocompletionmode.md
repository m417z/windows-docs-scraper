# IInkRecognizerContext::get_CharacterAutoCompletionMode

## Description

Gets or sets the character Autocomplete mode, which determines when characters or words are recognized.

This property is read/write.

## Parameters

## Remarks

Recognition can occur in [Full](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercharacterautocompletionmode) mode (all strokes have been input), **Partial** mode (partial input in specific order), or **Random** mode (partial input in random order).

For a list of the character Autocomplete mode values that you can use, see the [InkRecognizerCharacterAutoCompletionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercharacterautocompletionmode) enumeration type.

You cannot turn character Autocomplete off after it is set.

You must set the [Guide](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_guide) property before using this property.

Some recognizers do not support character Autocomplete. The [InkRecognizerCapabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) enumeration contains flags for features a recognizer can support. You can determine if the recognizer supports character Autocomplete by checking the value of the [Capabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities) property.

## See also

[Capabilities Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerCharacterAutoCompletionMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercharacterautocompletionmode)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)