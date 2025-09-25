# IInkRecognizerContext::putref_WordList

## Description

Gets or sets the word list that is used in the recognition process to improve the recognition results.

This property is read/write.

## Parameters

## Remarks

Setting this property succeeds only if the [Strokes](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-get_strokes) property is **NULL**. You must set the **WordList** property before you attach an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the **Strokes** property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) or you must set the **Strokes** property to **NULL** and then set the **WordList** property (and possibly reattach the InkStrokes collection).

To remove the current word list and use the user dictionary, set this property to **NULL**. Any subsequent modification of the [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) object does not modify the recognition outcome. If you want to change the word list, first set this property to **NULL**, modify the InkWordList, and then re-attach it to the InkRecognizerContext by assigning it to the **WordList** property.

Use the [Factoid](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_factoid) property to limit the search to the word list that is associated with the context. You may also need to set the [RecognitionFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags) property to improve the results.

Wordlist cannot be set after a factoid is set. This prevents a factoid from referring to a possibly non existent wordlist. Attempting to do so will result in an E_FAIL HRESULT value.

If a string is added to a word list, its capitalized versions are also implicitly added. For instance, adding "hello" implicitly adds "Hello" and "HELLO".

Using words longer than 256 characters will result in an E_POINTER exception when assigning the **WordList** property to [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class).

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class)