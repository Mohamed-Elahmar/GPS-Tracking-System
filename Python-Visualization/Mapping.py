
#
# %%
import folium

# Read locations from text file
locations = []
latitude = []
longitude = []
with open("coordinates.txt", "r") as file:
    latitudes_done = False
    for line in file:
        line = line.strip()  # Remove leading/trailing whitespaces

        if line == "logdone":
            break  # Exit the loop when 'logdone' is encountered

        if not line:  # Skip empty lines
            continue

        if line == "latdone":
            latitudes_done = True
            continue

        if not latitudes_done:
            if len(line) > 7:
                if line[0]=='3':
                    latitude.append(int(line[0:2]) + (float(line[2:]) / 60))
        else:
            if len(line) > 7:
                if line[0]=='3':
                    longitude.append(int(line[0:2]) + (float(line[2:]) / 60))

    for loc in range(len(longitude)):
        locations.append([latitude[loc], longitude[loc]])


m = folium.Map(location=locations[0], zoom_start=23)  # Start Point
for loc in locations:
    folium.Marker(location=loc).add_to(m)
# print(locations)
# display
m

# %%