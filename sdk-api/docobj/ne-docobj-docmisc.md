# DOCMISC enumeration

## Description

Provides miscellaneous property information about a document object.

## Constants

### `DOCMISC_CANCREATEMULTIPLEVIEWS:1`

Object supports multiple views.

### `DOCMISC_SUPPORTCOMPLEXRECTANGLES:2`

Object supports complex rectangles and therefore implements [IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex).

### `DOCMISC_CANTOPENEDIT:4`

Object supports activation in a separate window and therefore implements [IOleDocumentView::Open](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-open).

### `DOCMISC_NOFILESUPPORT:8`

Object does not support file read/write.

## Remarks

Objects that have a limited user interface for activation purposes should set DOCMISC_CANTOPENEDIT. Those that support [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) only as a persistence mechanism should specify DOCMISC_NOFILESUPPORT. Otherwise, an object must also implement [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile).

A combination of values from **DOCMISC** is returned at the location specified by the *pdwStatus* parameter in [IOleDocument::GetDocMiscStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-getdocmiscstatus).

If an object requires none of these flags, it must write a zero to the *pdwStatus* parameter.

## See also

[IOleDocument::GetDocMiscStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocument-getdocmiscstatus)

[IOleDocumentView::Open](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-open)

[IOleDocumentView::SetRectComplex](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-ioledocumentview-setrectcomplex)

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)