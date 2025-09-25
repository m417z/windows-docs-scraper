# ITextStory::GetType

## Description

Gets this story's type.

## Parameters

### `pValue` [out, retval]

Type: **long***

This story's type. It can be any of the following values, or a custom client value from 100 to 65535.

#### tomCommentsStory

#### tomEndnotesStory

#### tomEvenPagesFooterStory

#### tomEvenPagesHeaderStory

#### tomFindStory

#### tomFirstPageFooterStory

#### tomFirstPageHeaderStory

#### tomFootnotesStory

#### tomMainTextStory

#### tomPrimaryFooterStory

#### tomPrimaryHeaderStory

#### tomReplaceStory

#### tomScratchStory

#### tomTextFrameStory

#### tomUnknownStory

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)

[ITextStory::SetType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstory-gettype)