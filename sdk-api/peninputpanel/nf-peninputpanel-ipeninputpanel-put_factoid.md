# IPenInputPanel::put_Factoid

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets the string name of the factoid used by the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object.

This property is read/write.

## Parameters

## Remarks

A factoid provides a recognizer context for ink within a particular field. You specify a factoid if an input field is of a known type. For example, if the input field contains a date, specify the [Date](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) factoid.

For more information about factoids and how to use them, see [Using Context to Improve Accuracy](https://learn.microsoft.com/windows/desktop/tablet/using-context-to-improve-accuracy). For a list of possible values for the **Factoid** property, see [Supported Factoids from Version 1](https://learn.microsoft.com/windows/desktop/tablet/supported-factoids-from-version-1).

**Note** String representations of factoids are case-sensitive.

This property has no effect on keypads or keyboards.

The [WordList](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) factoid is not supported for the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object.

The default value for the **Factoid** property is DEFAULT. In locales that use recognizers of Latin script, all factoids may be used. In locales that use recognizers of East Asian characters, the following factoid values are relevant:

* DIGIT: Implies the Num bias button on the East Asian writing pad.
* ONECAHR: Implies the Alpha bias button on the East Asian writing pad.
* Common [factoids](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) (JapaneseCommon, ChineseSimpleCommon, ChineseTraditionalCommon, KoreanCommon, KanjiCommon, and HangulCommon) imply the Alpha/Num bias button on the East Asian writing pad.

All factoid values other than DIGIT and ONECHAR are interpreted as the common factoid that is appropriate for the current input locale.

If the **Factoid** property is set, it is forwarded to the recognizer only if the [SetInputScope](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscope) function has not also been called.

## See also

[Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants)

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)