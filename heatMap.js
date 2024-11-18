
export function loadHeatmap(time) {
    //var time = document.getElementById("time").value;
    /*
    var map = L.map('map').setView([45.501688, -73.567255], 12);

    // Add OpenStreetMap tiles documentation in readme
    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 19,
        attribution: '© OpenStreetMap contributors'
    }).addTo(map);
     */

    //var stations = [];
    //var points = [];
    //start test
    var heatData = [];

    fetch('./Resources/' + time + '.json')
        .then(response => response.json())
        .then(data => {
            // separate data, created an array for heatmap data
            const stations = data.network.stations;
            var heatData = [];
            //loop through the text file for information about every station
            stations.forEach(station => {
                const { latitude, longitude, free_bikes } = station;
                // Push data to array
                heatData.push([latitude, longitude, free_bikes * 2]);
            });
            // Create and add a new heatmap layer with the updated heatData array
            map.heatLayer = L.heatLayer(heatData, {
                //used the settings for the heat display that the example from the library used

                radius: 15

            }).addTo(map);
        })
        // Handle any errors that occur during the fetch or data processing
        .catch(error => console.error('Bricked:', error));


}
