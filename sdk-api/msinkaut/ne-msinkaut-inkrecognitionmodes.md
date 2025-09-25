# InkRecognitionModes enumeration

## Description

Specifies how the recognizer interprets the ink and determines the result string.

## Constants

### `IRM_None:0`

The recognizer applies no recognition modes.

### `IRM_WordModeOnly:0x1`

The recognizer treats the ink as a single word.

For example, if the recognizer context contains to get her, the recognizer returns together.

**Note** Some compound words in the dictionary are treated as single words by recognizers of Latin script. For example, recognizers of Latin script treat "Los Angeles" as a single word if you use the WordMode flag. In addition, certain factoids-such as the Date [Factoid](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) in English (United Kingdom), English (United States), German, and French-treat some multiple word dates as single words. For example, these recognizers treat "January 21, 2000" as a single word if you use the WordMode flag.

### `IRM_Coerce:0x2`

The recognizer coerces the result based on the factoid that you specified for the context.

For example, if you specified the Telephone factoid and the user enters the word hello, the recognizer may return a random phone number or an empty string. If you do not specify this flag, the recognizer returns hello as the result.

### `IRM_TopInkBreaksOnly:0x4`

The recognizer disables multiple segmentation.

This turns off the recognizer's ability to return recognition results based on more than one recognition segment of the ink, where each segment corresponds to a word (in recognizers of Latin script) or a character (in recognizers of East Asian characters).

In other words, the word together always returns alternates based on together being a single word, and the recognizer does not consider that the string might also be "to get her" or some other variation with differing segmentation.

Turning on this flag enhances recognition speed.

### `IRM_PrefixOk:0x8`

The recognizer applies partial word recognition.

### `IRM_LineMode:0x10`

The recognizer does not imply line breaking inside the recognizer and all of the ink is recognized as one line.

### `IRM_DisablePersonalization:0x20`

The recognizer disables personalization on the recognizer.

### `IRM_AutoSpace:0x40`

The recognizer should automatically determine word breaks between newly written (and recognized) text and the suffix and prefix.

For example, when AutoSpace is enabled and the user inserts bye after the recognized word, good, the recognizer returns bye with no space inserted before it as the recognized text because the compound "goodbye" is a valid word.

If the user inserts world after the recognized word, hello, the recognizer returns world with a space inserted before it as the recognized text to produce the words, hello world. If AutoSpace is disabled, the recognizer returns world with no space.

This flag is used only by recognizers of Latin script.

### `IRM_Max:0x80`

For internal use only.

## Remarks

In C++, explicit casting is required when trying to set more than one flag at a time using the bitwise **OR** operator. A compilation error occurs if explicit casting is not used.

## See also

[Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[RecognitionFlags Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags)