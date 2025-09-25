# IMiniportWavePciStream::RevokeMappings

## Description

The `RevokeMappings` method revokes mappings that were previously obtained through [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping).

## Parameters

### `FirstTag` [in]

Specifies the tag value that identifies the first mapping that is being revoked.

### `LastTag` [in]

Specifies the tag value that identifies the last mapping that is being revoked.

### `MappingsRevoked` [out]

Output pointer for the count of revoked mappings. This parameter points to a ULONG variable into which the method writes the number of mappings actually revoked by the call. This number excludes any mappings in the range *FirstTag* to *LastTag* that the miniport driver has already released. Due to synchronization issues, some of the mappings in the range might be released between the time that the port driver determines the list of mappings to be revoked and the call to `RevokeMappings`. For more information, see the following Remarks section.

## Return value

`RevokeMappings` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The port driver calls `RevokeMappings` to revoke the stream's mappings when:

* An I/O request (IRP) is canceled and the previously mapped memory might no longer be available.
* The stream state changes to KSSTATE_STOP (see [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)) and the device no longer has need for the mappings.

The miniport driver keeps track of the order in which it acquires its mappings from calls to [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping). The `RevokeMapping` method revokes all mappings in the sequence that begins with the mapping identified by *FirstTag* and ends with the mapping identified by *LastTag*. This includes the mappings identified by *FirstTag* and *LastTag* and all mappings in between. The miniport driver revokes each mapping by removing it from the list of available mappings.

The `RevokeMapping` method can be used to remove a single mapping by setting *FirstTag* and *LastTag* to the same value.

The port driver can call `RevokeMappings` asynchronously with respect to the miniport driver's maintenance operations on the DMA controller's scatter/gather transfer queue. Access to this queue needs to be protected by a synchronization primitive. For example, in the ac97 sample audio driver in the Microsoft Windows Driver Kit (WDK), this is done by surrounding critical code sections with [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) and [KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock) calls. Because the miniport driver can release mappings asynchronously with respect to the port driver's calls to `RevokeMappings`, the miniport driver might have previously released (see [IPortWavePciStream::ReleaseMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-releasemapping)) one or more of the mappings specified in the `RevokeMappings` call.

For more information about mappings, see [WavePci Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/wavepci-latency).

## See also

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping)

[IPortWavePciStream::ReleaseMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-releasemapping)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)