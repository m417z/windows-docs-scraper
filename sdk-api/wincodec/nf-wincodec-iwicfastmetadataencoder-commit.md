# IWICFastMetadataEncoder::Commit

## Description

Finalizes metadata changes to the image stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the commit fails and returns **WINCODEC_ERR_STREAMNOTAVAILABLE**, ensure that the image decoder was loaded using the **WICDecodeMetadataCacheOnDemand** option. A fast metadata encoder is not supported when the decoder is created using the **WICDecodeMetadataCacheOnLoad** option.

If the commit fails for any reason, you will need to re-encode the image to ensure the new metadata is added to the image.