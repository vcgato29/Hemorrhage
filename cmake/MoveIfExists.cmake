if(EXISTS ${ChkFile})
	message("-- Found ${ChkFile}, Moving to ${NewTarget}.")
	file(RENAME ${ChkFile} ${NewTarget})
endif()
