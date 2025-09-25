# IPersistTuneXmlUtility2::Serialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Serializes a tuning request to an XML tuning request string.

## Parameters

### `piTuneRequest` [in]

Pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo) interface for the tuning request object that is serialized.

### `pString`

Pointer to a buffer that receives the XML tuning request string. The caller is responsible for releasing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPersistTuneXmlUtility2](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ipersisttunexmlutility2)

[IPersistTuneXmlUtility::Deserialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ipersisttunexmlutility-deserialize)

[ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)