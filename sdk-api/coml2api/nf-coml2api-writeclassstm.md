# WriteClassStm function

## Description

The **WriteClassStm** function stores the specified CLSID in the stream.

## Parameters

### `pStm` [in]

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the stream into which the CLSID is to be written.

### `rclsid` [in]

Specifies the CLSID to write to the stream.

## Return value

This function returns HRESULT.

## Remarks

The
**WriteClassStm** function writes a CLSID to the specified stream object so it can be read by the
[ReadClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstm) function. Most applications do not call
**WriteClassStm** directly. OLE calls it before making a call to an object's
[IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method.

## See also

[ReadClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstg)

[ReadClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstm)

[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg)