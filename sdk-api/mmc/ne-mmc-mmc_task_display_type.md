# MMC_TASK_DISPLAY_TYPE enumeration

## Description

The
**MMC_TASK_DISPLAY_TYPE** enumeration is introduced in MMC 1.1.

The
**MMC_TASK_DISPLAY_TYPE** enumeration defines the types of image that can be displayed for a task or the background on a taskpad. These values are used in the **eDisplayType** member of the
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure.

For that which displays the task image, the
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure is the **sDisplayObject** member of the
[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task) structure, which is filled in by the
[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) method.

For that which displays the background image, the
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure is filled in by the
[IExtendTaskPad::GetBackground](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getbackground) method.

## Constants

### `MMC_TASK_DISPLAY_UNINITIALIZED:0`

No images specified.

### `MMC_TASK_DISPLAY_TYPE_SYMBOL`

The image displayed for the task or background is the symbol specified by an
[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol) structure.

### `MMC_TASK_DISPLAY_TYPE_VANILLA_GIF`

The image displayed for the task or background is a transparent GIF image.

The GIF image is specified by an
[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) structure.

**Note** There is no difference between **MMC_TASK_DISPLAY_TYPE_VANILLA_GIF** and **MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF**.

### `MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF`

The image displayed for the task or background is a transparent GIF image.

The GIF image is specified by an
[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) structure.

**Note** There is no difference between **MMC_TASK_DISPLAY_TYPE_VANILLA_GIF** and **MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF**.

### `MMC_TASK_DISPLAY_TYPE_BITMAP`

The image displayed for the task or background is a nontransparent bitmap image.

The bitmap image is specified by an
[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) structure.