HRESULT AddPage(
  [in] IXpsOMPage                   *page,
  [in] const XPS_SIZE               *advisoryPageDimensions,
  [in] IXpsOMPartUriCollection      *discardableResourceParts,
  [in] IXpsOMStoryFragmentsResource *storyFragments,
  [in] IXpsOMPrintTicketResource    *pagePrintTicket,
  [in] IXpsOMImageResource          *pageThumbnail
);