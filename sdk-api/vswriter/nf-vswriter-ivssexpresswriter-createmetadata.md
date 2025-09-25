# IVssExpressWriter::CreateMetadata

## Description

Creates an express writer metadata object and returns an [IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata) interface pointer to it.

## Parameters

### `writerId` [in]

The globally unique identifier (GUID) of the writer class.

### `writerName` [in]

A null-terminated wide character string that contains the name of the writer class. This string is not localized.

### `usageType` [in]

A [VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type) enumeration value that indicates how the data that is managed by the writer is used on the host system. The only valid values for this parameter are VSS_UT_BOOTABLESYSTEMSTATE, VSS_UT_SYSTEMSERVICE, and VSS_UT_USERDATA.

### `versionMajor` [in]

The major version of the writer application. For more information, see the Remarks section.

### `versionMinor` [in]

The minor version of the writer application. For more information, see the Remarks section.

### `reserved` [in]

This parameter is reserved for system use.

### `ppMetadata` [out]

A pointer to a variable that receives an [IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata) interface pointer to the newly created express writer metadata.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *versionMajor* and *versionMajor* parameters are used to specify the writer's major and minor version numbers according to the following VSS conventions:

* A writer's minor version number should be incremented by one whenever a released version of the writer contains minor changes that affect the writer's interaction with requesters. For example, a correction to a file specification in a writer QFE or service pack would justify incrementing the minor version number. However, a change between beta or release candidate versions of a writer would not justify the changing of the minor version number.
* A writer's major version number should be incremented by one whenever a released version of the writer contains a significant change. For example, if data that is backed up with a new version of a writer cannot be restored using the previous version of the writer, the new writer's major version number should be incremented.
* Whenever the major version number is incremented, the minor version number should be reset to zero.

If a writer does not specify a version number, VSS will assign a default version number of 0.0.

## See also

[CreateVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-createvssexpresswriter)

[IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter)