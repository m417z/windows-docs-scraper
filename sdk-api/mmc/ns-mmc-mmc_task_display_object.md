# MMC_TASK_DISPLAY_OBJECT structure

## Description

The
**MMC_TASK_DISPLAY_OBJECT** structure is introduced in MMC 1.1.

The
**MMC_TASK_DISPLAY_OBJECT** structure specifies the type of image and all the data required to use that image to display a task or the background on a taskpad.

For that which displays the task image, the
**MMC_TASK_DISPLAY_OBJECT** structure is the **sDisplayObject** member of the
[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task) structure, which is filled in by the
[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) method.

For that which displays the background image, the
**MMC_TASK_DISPLAY_OBJECT** structure is filled in by the
[IExtendTaskPad::GetBackground](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getbackground) method.

## Members

### `eDisplayType`

Value of type
[MMC_TASK_DISPLAY_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_task_display_type) that specifies the type of image displayed as the background. The image can be one of three types: symbol, GIF, or bitmap.

### `uBitmap`

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) structure that contains the resource paths to the image files of the image type specified by **eDisplayType**.
**MMC_TASK_DISPLAY_BITMAP** contains the paths to the two images used when the user moves the mouse over a task and when the task is deselected.

The **uBitmap** member is used only if **eDisplayType** is one of the following values:

* **MMC_TASK_DISPLAY_TYPE_BITMAP**
* **MMC_TASK_DISPLAY_TYPE_VANILLA_GIF**
* **MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF**

The **MMC_TASK_DISPLAY_TYPE_BITMAP** value indicates that a non-transparent image is being used for the task or background. The **MMC_TASK_DISPLAY_TYPE_VANILLA_GIF** and **MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF** values indicate that a transparent image is being used for the task or background.

**Note** There is no difference between **MMC_TASK_DISPLAY_TYPE_VANILLA_GIF** and **MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF**.

### `uSymbol`

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol) structure that contains the font name, EOT (embedded OpenType) resource path, and characters to display as the image.

The **uSymbol** is used only if **eDisplayType** is **MMC_TASK_DISPLAY_TYPE_SYMBOL**.

## See also

[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next)

[IExtendTaskPad::GetBackground](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getbackground)

[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task)

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap)

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol)

[MMC_TASK_DISPLAY_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_task_display_type)