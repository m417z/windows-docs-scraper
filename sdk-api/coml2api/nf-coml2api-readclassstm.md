# ReadClassStm function

## Description

The
**ReadClassStm** function
reads the CLSID previously written to a stream object with the
[WriteClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstm) function.

## Parameters

### `pStm` [in]

A pointer to the
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface on the stream object that contains the CLSID to be read. This CLSID must have been previously written to the stream object using
[WriteClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstm).

### `pclsid` [out]

A pointer to where the CLSID is to be written.

## Return value

This function also returns any of the error values returned by the
[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) method.

## Remarks

Most applications do not call the
**ReadClassStm** function directly. COM calls it before making a call to an object's
[IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load) implementation.

## See also

[ReadClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstg)

[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg)

[WriteClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstm)