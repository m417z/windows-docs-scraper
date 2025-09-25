# VMEMHEAP structure

## Description

The VMEMHEAP structure contains information about the heap.

## Members

### `dwFlags`

Reserved for system use and should be ignored by the driver.

### `stride`

Reserved for system use and should be ignored by the driver.

### `freeList`

Reserved for system use and should be ignored by the driver.

### `allocList`

Reserved for system use and should be ignored by the driver.

### `dwTotalSize`

Reserved for system use and should be ignored by the driver.

### `fpGARTLin`

Points to the linear graphic address remapping table (GART) address of the start of the heap for nonlocal display memory.

### `fpGARTDev`

Points to the physical GART address of the start of the heap for nonlocal display memory.

### `dwCommitedSize`

Reserved for system use and should be ignored by the driver.

### `dwCoalesceCount`

Reserved for system use and should be ignored by the driver.

### `Alignment`

Reserved for system use and should be ignored by the driver.

### `ddsCapsExAlt`

Reserved for system use and should be ignored by the driver.

### `ddsCapsEx`

Reserved for system use and should be ignored by the driver.

### `liPhysAGPBase`

Reserved for system use and should be ignored by the driver.

### `hdevAGP`

Reserved for system use and should be ignored by the driver.

### `pvPhysRsrv`

Reserved for system use and should be ignored by the driver.

### `pAgpCommitMask`

Reserved for system use and should be ignored by the driver.

### `dwAgpCommitMaskSize`

Reserved for system use and should be ignored by the driver.