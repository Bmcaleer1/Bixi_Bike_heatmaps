
export function loadMap() {
    const map = L.map('map').setView([45.501688, -73.567255], 12);

// Add OpenStreetMap tiles documentation in readme
    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 19,
        attribution: '© OpenStreetMap contributors'
    }).addTo(map);
    return map;
}

