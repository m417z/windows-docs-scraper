## Description

Generates a license request based on the provided data.

## Parameters

### `initDataType`

A **LPCWSTR** specifying the type of the data provided in the *initData* parameter. The string format is specified by the Encrypted Media Extension specification's [Initialization Data Type](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#initialization-data-type).

### `initData`

A **BYTE** array containing initialization data. The data format is specified by the Encrypted Media Extension specification's [Initialization Data](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#initialization-data).

### `initDataSize`

The size of the **BYTE** array provided in the *initData* parameter.

## Return value

Returns S_OK on success.

## Remarks

**GenerateRequest** is based on the Encrypted Media Extension specification's [MediaKeySession.generateRequest](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-generaterequest).

## See also