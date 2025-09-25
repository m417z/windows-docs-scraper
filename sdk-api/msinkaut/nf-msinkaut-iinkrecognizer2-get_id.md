# IInkRecognizer2::get_Id

## Description

Retrieves the ID for the InkRecognizer.

## Parameters

### `pbstrId` [out]

A BSTR containing the ID of the recognizer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To access this method, first create and instance of the [InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class), then call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get a pointer to the [IInkRecognizer2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer2). Use this pointer to call the **get_Id** method.

## See also

[IInkRecognizer2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer2)