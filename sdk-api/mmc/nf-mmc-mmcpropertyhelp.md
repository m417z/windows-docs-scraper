# MMCPropertyHelp function

## Description

The MMCPropertyHelp function is introduced in MMC 1.1.

The MMCPropertyHelp function displays the specified HTML Help topic in the merged MMC HTML Help file for a property page.

## Parameters

### `pszHelpTopic`

A pointer to a NULL-terminated string specifying the topic to display in the merged MMC HTML Help file. The string must have the following format:

*helpfilename*::*topicfilename*

where *helpfilename* is the file name of the snap-in's HTML Help file (.chm) that MMC merged into the MMC HTML Help file (file name only, not the path to the original HTML Help file) and *topicfilename* is the internal path to the topic file within the snap-in's .chm file. The author of the snap-in's HTML Help file determines whether there is an internal directory structure for the topic HTML files or if all topic HTML files are at the root of the .chm file.

For example, if the snap-in had the HTML Help file mysnapin.chm merged into the MMC HTML Help file and a topic HTML file that had the internal Help file path of htm/snphlp01.htm, the string would have the following form:

mysnapin.chm::htm/snphlp01.htm

Support for numeric IDs for topics is not available in this release.

## Return value

This callback function can return one of these values.

## Remarks

Call
MMCPropertyHelp in the notification handler for the
[MMCN_CONTEXTHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-contexthelp) notification.

A snap-in can provide context help on a property page. Because an MMC property sheet is typically running on a separate thread, the property page cannot use the
[IDisplayHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-idisplayhelp) interface directly. Instead, the property page can call
MMCPropertyHelp from the MMC library to achieve the same result.
MMCPropertyHelp takes the same topic string parameter as
[IDisplayHelp::ShowTopic](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-idisplayhelp-showtopic) and handles marshaling the request to the main MMC thread.

If the snap-in handles the [MMCN_CONTEXTHELP](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-contexthelp) notification, MMC expects the snap-in to specify a Help topic for the selected item. Consequently, in the notification handler for the **MMCN_CONTEXTHELP** notification, the snap-in has two options:

* It can call [IDisplayHelp::ShowTopic](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-idisplayhelp-showtopic) or
  *MMCPropertyHelp* to specify the Help topic and then return **S_OK** to indicate success. Be aware that the snap-in should only return **S_OK** if it specifies a Help topic. If the snap-in returns **S_OK** without specifying a Help topic, no Help topic will be displayed.
* It can return S_FALSE to the notification. MMC then brings up the table of contents with the default MMC topic selected.

## See also

[IDisplayHelp::ShowTopic](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-idisplayhelp-showtopic)

[ISnapinHelp2::GetHelpTopic](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814944(v=vs.85))