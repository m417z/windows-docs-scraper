# IRoMetaDataLocator structure

## Description

Enables the [RoGetParameterizedTypeInstanceIID](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/nf-roparameterizediid-rogetparameterizedtypeinstanceiid) function to access run-time metadata.

Implement **IRoMetaDataLocator** when you're implementing programming language bindings to enable a language to call Windows platform APIs by using Windows metadata (.winmd) files.

## Members

### `Locate`

Gets a metadata builder for the specified type.

#### nameElement

A Windows Runtime type or parameterized type to resolve.

#### metaDataDestination

A data sink for Windows Runtime metadata. The caller should invoke the appropriate set method to provide the metadata for the type named by *nameElement*.

## See also

[RoGetMetaDataFile](https://learn.microsoft.com/windows/desktop/api/rometadataresolution/nf-rometadataresolution-rogetmetadatafile)