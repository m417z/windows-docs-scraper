# PFN_CRYPT_XML_DATA_PROVIDER_READ callback function

## Description

The *PFN_CRYPT_XML_DATA_PROVIDER_READ* callback function reads XML data.

## Parameters

### `pvCallbackState` [in, out]

A pointer to an application defined argument that is passed to the calling function.

### `pbData` [out]

A pointer to the buffer that receives the data to be read.

### `cbData` [in]

The size, in bytes, of the data to be read.

### `pcbRead` [out]

A pointer to a variable that receives the number of bytes actually read.

## Return value

 The *PFN_CRYPT_XML_DATA_PROVIDER_READ* callback function returns a value when one of the
following conditions occurs:

* A write operation completes on the data provider
* The number of bytes requested is read
* An error occurs

If the function succeeds, the function returns NO_ERROR.

If the function fails, it returns an **HRESULT** value that indicates the error.

If the value of *pcbRead* equals zero, then there is no more data available.

## Remarks

 The callback function does not return a value unless the number of bytes specified in *cbData*
is available or the last block of data has been read.