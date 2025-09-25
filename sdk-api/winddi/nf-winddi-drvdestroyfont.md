# DrvDestroyFont function

## Description

The **DrvDestroyFont** function notifies the driver that a font realization is no longer needed and that the driver can now free any associated data structures it has allocated.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure that identifies the font instance.

## Remarks

The **DrvDestroyFont** function is called only in font drivers and kernel-mode printer drivers.

If the DEVICE_FONTTYPE flag is set in the **flFontType** member of the FONTOBJ structure, the driver should release any resources or memory identified with both the **pvConsumer** and **pvProducer** members of FONTOBJ. Otherwise, it should release only memory and resources identified with **pvConsumer**.

The driver must reset the **pvConsumer** and **pvProducer** members to **NULL** if it uses them.

GDI calls **DrvDestroyFont** once for the font producer and once again for the font consumer.

GDI guarantees that **DrvDestroyFont** and [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) never overlap; consequently, the driver can rely on cached information while processing a **DrvTextOut** call.

This function must be implemented if the font driver or kernel-mode printer driver allocates resources when it realizes fonts.

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)