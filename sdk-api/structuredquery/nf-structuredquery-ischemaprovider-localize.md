# ISchemaProvider::Localize

## Description

Localizes the currently loaded schema for a specified locale.

## Parameters

### `lcid` [in]

Type: **LCID**

The locale to localize for.

### `pSchemaLocalizerSupport` [in]

Type: **[ISchemaLocalizerSupport](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemalocalizersupport)***

Pointer to an [ISchemaLocalizerSupport](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemalocalizersupport) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before this method is called, the loaded schema should typically be a schema that is not localized, such as the one in %SYSTEMROOT%\System32\StructuredQuerySchema.bin. This method makes the loaded schema suitable for parsing queries in the specified locale, using the object specified in the *pSchemaLocalizerSupport* parameter. The localized schema can then be saved into a schema binary by calling the [ISchemaProvider::SaveBinary](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-ischemaprovider-savebinary) method.

Most applications should use [CreateLoadedParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparsermanager-createloadedparser) to obtain a query parser loaded with a localized schema, instead of using this method explicitly.