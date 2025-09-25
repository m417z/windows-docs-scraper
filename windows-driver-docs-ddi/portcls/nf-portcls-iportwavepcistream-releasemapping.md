# IPortWavePciStream::ReleaseMapping

## Description

The `ReleaseMapping` method releases a mapping that was obtained by a previous call to [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping).

## Parameters

### `Tag` [in]

Specifies a tag value identifying the mapping that is to be released. For more information, see the following Remarks section.

## Return value

`ReleaseMapping` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Set the *Tag* parameter to the same tag value that you used to identify the mapping in the call to [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping) that originally obtained the mapping.

The miniport driver must keep track of the order in which it acquires its mappings from calls to **IPortWavePciStream::GetMapping**, and it must release the mappings in the same order.

To avoid potential deadlocks, the miniport driver must avoid holding a spin lock during its call to `ReleaseMapping`. See the ac97 sample audio driver in the Microsoft Windows Driver Kit (WDK) for a code example that uses a spin lock to serialize accesses to shared data structures and peripherals in a multiprocessor system. The sample code calls [KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock) before calling `ReleaseMapping` and calls [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) after calling `ReleaseMapping`. Between the calls to release and acquire the spin lock, the driver thread must not assume that it has exclusive access to the data or peripherals that are guarded by the spin lock. The Driver Verifier tool (see the description of this tool at the [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/driver-verifier) website) checks for active spin locks during calls to `ReleaseMapping`; if it detects one, it generates a 0xC4 (deadlock detection) bug check.

## See also

[IMiniportWavePciStream::RevokeMappings](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-revokemappings)

[IPortWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepcistream)

[IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping)

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)