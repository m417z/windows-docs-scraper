# InkRecognizerCapabilities enumeration

## Description

Specifies the attributes of a recognizer. You also use this enumeration to determine which attributes to use when you search for an installed recognizer.

## Constants

### `IRC_DontCare:1`

Ignores all other flags that are set.

### `IRC_Object:2`

The recognizer performs object recognition; otherwise, the recognizer performs text recognition.

### `IRC_FreeInput:4`

The recognizer supports free input. Ink is entered without the use of a recognition guide, such as lines or boxes.

### `IRC_LinedInput:8`

The recognizer supports lined input, which is similar to writing on lined paper.

### `IRC_BoxedInput:16`

The recognizer supports boxed input, in which each character or word is entered in a box.

### `IRC_CharacterAutoCompletionInput:32`

The recognizer supports character Autocomplete. Recognizers that support character Autocomplete require boxed input.

### `IRC_RightAndDown:64`

The recognizer supports western and Asian languages.

### `IRC_LeftAndDown:128`

The recognizer supports Hebrew and Arabic languages.

### `IRC_DownAndLeft:256`

The recognizer supports Asian languages.

### `IRC_DownAndRight:512`

The recognizer supports the Chinese language.

### `IRC_ArbitraryAngle:1024`

The recognizer supports text that is written at arbitrary angles.

### `IRC_Lattice:2048`

The recognizer can return a lattice object.

### `IRC_AdviseInkChange:4096`

The recognizer's background recognition can be interrupted, as in when the ink has changed.

### `IRC_StrokeReorder:8192`

Specifies that stroke order - spatial and temporal - is handled.

### `IRC_Personalizable:16384`

The recognizer supports personalization.

### `IRC_PrefersArbitraryAngle:32768`

### `IRC_PrefersParagraphBreaking:65536`

### `IRC_PrefersSegmentation:131072`

### `IRC_Cursive:262144`

### `IRC_TextPrediction:524288`

### `IRC_Alpha:1048576`

### `IRC_Beta:2097152`

## Remarks

This enumeration is a flag.

## See also

[Capabilities Property [IInkRecognizer Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities)

[Guide Property [InkRecognizerContext Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_guide)

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)