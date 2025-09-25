# STATDATA structure

## Description

Contains information used to specify each advisory connection. It is used for enumerating current advisory connections. It holds data returned by the [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) enumerator. This enumerator interface is returned by [IDataObject:DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise). Each advisory connection is specified by a unique **STATDATA** structure.

## Members

### `formatetc`

The [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure for the data of interest to the advise sink. The advise sink receives notification of changes to the data specified by this **FORMATETC** structure.

### `advf`

The [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration value that determines when the advisory sink is notified of changes in the data.

### `pAdvSink`

The pointer for the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface that will receive change notifications.

### `dwConnection`

The token that uniquely identifies the advisory connection. This token is returned by the method that sets up the advisory connection.

## See also

[IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata)