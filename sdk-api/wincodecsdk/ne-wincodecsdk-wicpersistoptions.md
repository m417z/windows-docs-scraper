# WICPersistOptions enumeration

## Description

Specifies Windows Imaging Component (WIC) options that are used when initializing a component with a stream.

## Constants

### `WICPersistOptionDefault:0`

The default persist options. The default is **WICPersistOptionLittleEndian**.

### `WICPersistOptionLittleEndian:0`

The data byte order is little endian.

### `WICPersistOptionBigEndian:0x1`

The data byte order is big endian.

### `WICPersistOptionStrictFormat:0x2`

The data format must strictly conform to the specification.

**Warning** This option is inconsistently implement and should not be relied on.

### `WICPersistOptionNoCacheStream:0x4`

No cache for the metadata stream.

Certain operations, such as [IWICComponentFactory::CreateMetadataWriterFromReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nf-wincodecsdk-iwiccomponentfactory-createmetadatawriterfromreader) require that the reader have a stream. Therefore, these operations will be unavailable if the reader is initialized with **WICPersistOptionNoCacheStream**.

### `WICPersistOptionPreferUTF8:0x8`

Use UTF8 instead of the default UTF16.

**Note** This option is currently unused by WIC.

### `WICPersistOptionMask:0xffff`

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) mask.

## See also

[GetPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nf-wincodecsdk-iwicstreamprovider-getpersistoptions)