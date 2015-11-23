// console user interface
// Author: Max Schwarz <max.schwarz@uni-bonn.de>

#ifndef UI_H
#define UI_H

#include "launch_config.h"
#include "fd_watcher.h"
#include "terminal.h"

#include <ros/wall_timer.h>

#include <map>

namespace rosmon
{

class UI
{
public:
	explicit UI(LaunchConfig* config, const FDWatcher::Ptr& fdWatcher);
	~UI();

	void update();
	void log(const std::string& channel, const std::string& str);
private:
	struct ChannelInfo
	{
		ChannelInfo()
		{}

		ChannelInfo(uint32_t color)
		 : labelColor(color)
		{}

		uint32_t labelColor;
		Terminal::Parser parser;
	};

	void drawStatusLine();
	void checkWindowSize();
	void setupColors();
	void handleInput();

	LaunchConfig* m_config;
	FDWatcher::Ptr m_fdWatcher;

	Terminal m_term;

	int m_columns;
	ros::WallTimer m_sizeTimer;

	std::map<std::string, ChannelInfo> m_nodeColorMap;

	int m_selectedNode;

	std::string m_strSetColor;
};

}

#endif

