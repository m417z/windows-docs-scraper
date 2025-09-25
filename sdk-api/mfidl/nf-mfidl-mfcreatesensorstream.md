# MFCreateSensorStream function

## Description

Creates an instance of the [IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream) interface.

## Parameters

### `StreamId`

The identifier for the created stream. This is the same as setting the [MF_DEVICESTREAM_STREAM_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-devicestream-stream-id) attribute. This value is used if *pAttributes* is null.

### `pAttributes` [in, optional]

The attribute store for the created stream.

### `pMediaTypeCollection` [in]

The collection of [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) objects specifying the media types supported by the stream.

### `ppStream` [out]

The created stream interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup) is null. |
| **E_INVALIDARG** | The supplied **LPCWSTR** is null. |