# IInkEdit::put_Factoid

## Description

Gets or sets the [Factoid](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) constant that a [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object uses to constrain its search for the recognition result.

This property is read/write.

## Parameters

## Remarks

This property should only be changed if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns IES_Idle.

To ensure that ink is recognized in the correct field context, set this property before processing the ink for the first time.

A [Factoid](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) provides context for recognized ink in the context of a particular field. You specify a factoid if an input field is of a known type, for example, if the input field contains a date.

This property takes or returns a string parameter and not a class object of the [Factoid](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) class. The members of this class are of type STRING. This method does not throw an error if you attempt to set this property to an invalid string value.

**Note** All factoids are case sensitive.

For more information about factoids and how to use them, see [Using Context to Improve Accuracy](https://learn.microsoft.com/windows/desktop/tablet/using-context-to-improve-accuracy). For a list of supported factoids, see [Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) and [Supported Factoids from Version 1](https://learn.microsoft.com/windows/desktop/tablet/supported-factoids-from-version-1).

## See also

[Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants)

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)