void CheckVersion(string version) {
	if (DownloadString(XorStr("https://pastebin.com/raw/BlaBla").c_str()) != version) {
		MessageBoxA(NULL, XorStr("Your version is outdated!").c_str(), XorStr("Old version!").c_str(), MB_ICONERROR);
		SetConsoleTitle(XorStr(L"Scotch Loader V.0.06 | Scotch#5627").c_str());
		ShowWindow(::GetConsoleWindow(), SW_SHOW);
		std::cout << XorStr("Do you want to load the newest version? (Y/N)\n");
		string eingabeUpdate;
		ClearEnter();
		cin >> eingabeUpdate;
		if(eingabeUpdate == "Y" || eingabeUpdate == "y")
		{
			SetConsoleTitle(XorStr(L"Updating loader... | Scotch#5627").c_str());
			string DownloadLinkVorKonvert = DownloadString(XorStr("https://pastebin.com/raw/BlaBla").c_str());
			LPCSTR DownloadLink = DownloadLinkVorKonvert.c_str();
			URLDownloadToFileA(0, DownloadLink, XorStr("C:\\Scotch Menu Updated.exe").c_str(), 0, 0);
			ShowWindow(::GetConsoleWindow(), SW_HIDE);
			MessageBoxW(0, XorStr(L"The new loader is in C:\n").c_str(), XorStr(L"UPDATED").c_str(), MB_ICONINFORMATION);
			renameZuAlt();
			exit(0);
		}
		else if (eingabeUpdate == "N" || eingabeUpdate == "n")
		{
			exit(0);
		}
		else
		{
			std::cout << XorStr("Wrong input!\n");
			Sleep(2000);
			exit(1);
		}
	}
}
