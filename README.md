For this project, I collaborated with a partner to develop a program that integrates Bash, C++, and web technologies to provide real-time and historical data about BIXI bike locations in Montreal. The project consists of three main components:

Bash Script: We wrote a Bash script to periodically pull data from the BIXI bike API, which provides real-time information about bike availability at various docking stations. The script runs at regular intervals and ensures the data is up-to-date.

C++ Data Processing: Using C++, we processed and sorted the API data to track bike availability at each station over time. The C++ program handled the heavy lifting of analyzing and storing the historical bike data, enabling us to generate accurate statistics for later viewing.

Website and Heatmap: The processed data was then passed to a website, which we designed to display the information in the form of a heatmap. The website allows users to view bike availability across different stations on a dynamic map, with color-coded stations to indicate bike availability (green for 10+ bikes, yellow for 5-10 bikes, and red for fewer than 5 bikes). Additionally, users can interact with the heatmap to explore historical data, selecting different times within the past hour to see the bike availability for those specific moments.
